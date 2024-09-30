#include "Photomode_Control.h"
#include "Engine/Engine.h"
#include "HighResScreenshot.h"
#include "ImageUtils.h"
#include "Windows/WindowsPlatformApplicationMisc.h"
#include "Misc/FileHelper.h"

UPhotomode_Control::UPhotomode_Control()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPhotomode_Control::BeginPlay()
{
	Super::BeginPlay();
}

void UPhotomode_Control::CaptureAndCopyToClipboard()
{
	CaptureScreenshot();
}

void UPhotomode_Control::CaptureScreenshot()
{
	// Get window resolution
	
	const int32 InSizeX = 256; // Example resolution (can be modified)
	const int32 InSizeY = 256;

	TArray<FColor> ImageData;
	ImageData.SetNum(InSizeX * InSizeY);

	FHighResScreenshotConfig& Config = GetHighResScreenshotConfig();
	Config.SetResolution(InSizeX, InSizeY);
	Config.bCaptureHDR = false;

	// Request the screenshot
	FScreenshotRequest::RequestScreenshot(false);
	FString FilePath = FScreenshotRequest::GetFilename();

	TArray64<uint8> RawImageData64;

	if (FPaths::FileExists(FilePath))
	{
		if (FFileHelper::LoadFileToArray(RawImageData64, *FilePath))
		{
			FImageUtils::PNGCompressImageArray(InSizeX, InSizeY, ImageData, RawImageData64);
		}

		// Copy to clipboard
		CopyImageToClipboard(InSizeX, InSizeY, ImageData);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Screenshot file not found: %s"), *FilePath);
	}
}

void UPhotomode_Control::CopyImageToClipboard(int32 InSizeX, int32 InSizeY, const TArray<FColor>& InImageData)
{
	TArray64<uint8> RawImageData64;
	FImageUtils::PNGCompressImageArray(InSizeX, InSizeY, InImageData, RawImageData64);

	FString ClipboardImage = FBase64::Encode(TArray<uint8>(RawImageData64));

	// Platform-specific clipboard copy
#if PLATFORM_WINDOWS
	FWindowsPlatformApplicationMisc::ClipboardCopy(*ClipboardImage);
#else
	FPlatformApplicationMisc::ClipboardCopy(*ClipboardImage);
#endif

	UE_LOG(LogTemp, Warning, TEXT("Image copied to clipboard."));
}

