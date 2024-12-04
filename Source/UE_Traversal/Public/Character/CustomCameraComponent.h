// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "CustomCameraComponent.generated.h"

/**
 * 
 */
UCLASS()
class UE_TRAVERSAL_API UCustomCameraComponent : public UCameraComponent
{
public:
	GENERATED_BODY()
	
	UCustomCameraComponent();

	void Rotate(const struct FInputActionValue& axis);

private:
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector GetPredictLocation();
	FRotator GetRotation(float DeltaTime);
	
	class ACharacter_Main *Character = nullptr;
	class USpringArmComponent *BoomStick = nullptr;

	UPROPERTY(EditAnywhere, Category = "Camera|Lag")
	float RotationInputLag = 8.0f;
	UPROPERTY(EditAnywhere, Category = "Camera|Lag")
	float OrientationLag = 1.0f;
	UPROPERTY(EditAnywhere, Category = "Camera|Lag")
	float PositionLag = 2.0f;
	UPROPERTY(EditAnywhere, Category = "Camera|Lag")
	float ForwardDelta = 1.0f;
	UPROPERTY(EditAnywhere, Category = "Camera|Lag")
	float StartZone = 200.0f;
	UPROPERTY(EditAnywhere, Category = "Camera|Lag")
	float EndZone = 1.0f;

	bool SeekPlayer = false;
};
