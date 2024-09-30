#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Photomode_Control.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UPhotomode_Control : public UActorComponent
{
	GENERATED_BODY()

public:
	UPhotomode_Control();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "PhotoMode")
	void CaptureAndCopyToClipboard();

	static void CopyImageToClipboard(int32 InSizeX, int32 InSizeY, const TArray<FColor>& InImageData);

private:
	void CaptureScreenshot();
};
