// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
//#include"Engine.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController {
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	bool GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	void AimTowardsEnemy();
	bool GetLookDirection(FVector2D screenLocation, FVector& worldDirection) const;
	bool GetSightRayHitLocation(FVector& hitLocation) const;

	UPROPERTY(EditAnywhere) float crossHair_Position_X = 0.5;
	UPROPERTY(EditAnywhere) float crossHair_Position_Y = 0.5;
private:
	float lineTraceRange = 10000000;
	float lookDirection = 1000000;
};
