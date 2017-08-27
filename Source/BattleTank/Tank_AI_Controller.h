// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "GameFramework/PlayerController.h"
//#include "Engine.h"
#include "Tank_AI_Controller.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATank_AI_Controller : public AAIController {
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	//virtual void Tick(float deltaTime) override;
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
private:
	//void AimTowardsEnemy();
	//bool GetSightRayHitLocation(FVector& hitLocation) const;
	//bool GetLookDirection(FVector2D screenLocation, FVector& worldDirection) const;
	virtual void Tick(float deltaSeconds) override;
	UPROPERTY(EditAnywhere) float crossHair_Position_X = 0.5;
	UPROPERTY(EditAnywhere) float crossHair_Position_Y = 0.3333;
};