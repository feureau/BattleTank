// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel_StaticMeshComponent.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel_StaticMeshComponent : public UStaticMeshComponent {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = Setup) float maxDegreesPerSecond = 5;
	UPROPERTY(EditAnywhere, Category = Setup) float minDegreesPerSecond = 40;
	UPROPERTY(EditAnywhere, Category = Setup) float maxElevationDegrees = 20;
	UPROPERTY(EditAnywhere, Category = Setup) float minElevationDegrees = 0;
	void Elevate(float degreesPerSecond);
};
