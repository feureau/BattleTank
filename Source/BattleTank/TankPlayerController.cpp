// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* controlledTank = GetControlledTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possessing Tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing Tank name: %s"), *(controlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Beginplay"));
}
void ATankPlayerController::Tick(float deltaTime) {
	Super::Tick(deltaTime);
	AimTowardsEnemy();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankPlayerController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const {
	FHitResult hitResult;
	auto startLocation = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();
	auto endLocation = startLocation + (lookDirection * lineTraceRange);
	//UE_LOG(LogTemp, Warning, TEXT("lookDirection. %s"), *endLocation.ToString());
	if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility)) {
		DrawDebugLine(GetWorld(),
			startLocation,
			endLocation,
			FColor(255, 0, 0),
			false, -1, 0,
			12.333
		);
		hitLocation = hitResult.Location;
		return true;
	} else {
		return false;
	}
}

bool  ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& worldDirection) const {
	FVector cameraWorldLocation;
	return (GetWorld()->GetFirstPlayerController()->DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, worldDirection));
}

void ATankPlayerController::AimTowardsEnemy() {
	if (!GetControlledTank()) {
		//return;
	} else {
		FVector HitLocation;
		if (GetSightRayHitLocation(HitLocation)) {
			GetControlledTank()->AimAt(HitLocation);
		}
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const {
	int32 viewPortSize_X, viewPortSize_Y;
	GetWorld()->GetFirstPlayerController()->GetViewportSize(viewPortSize_X, viewPortSize_Y);
	auto screenLocation = FVector2D(viewPortSize_X* crossHair_Position_X, viewPortSize_Y * crossHair_Position_Y);
	//UE_LOG(LogTemp, Warning, TEXT("Screen location: %s"), *(screenLocation.ToString()));
	hitLocation = FVector(1.0f);
	FVector lookDirection;
	if (GetLookDirection(screenLocation, lookDirection)) {
		GetLookVectorHitLocation(lookDirection, hitLocation);

		//UE_LOG(LogTemp, Warning, TEXT("Got here. %s"), *hitLocation.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("Look hitLocation: %s"), *hitLocation.ToString());
	}
	return true;
}