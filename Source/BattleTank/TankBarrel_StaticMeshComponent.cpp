// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel_StaticMeshComponent.h"
#include "BattleTank.h"

void UTankBarrel_StaticMeshComponent::Elevate(float degreesPerSecond) {
	//float time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("Elevate at: %s. Time: %s"), *(FString::SanitizeFloat(degreesPerSecond)), *(FString::SanitizeFloat(time)));
	float elevationChange = degreesPerSecond * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float rawNewElevation = RelativeRotation.Pitch + elevationChange;
	float targetElevation = FMath::Clamp<float>(rawNewElevation, minElevationDegrees, maxElevationDegrees);
	SetRelativeRotation(FRotator(targetElevation, 0.0f, 0.0f));
}