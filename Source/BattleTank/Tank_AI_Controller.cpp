// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_AI_Controller.h"
#include "Battletank.h"

void ATank_AI_Controller::BeginPlay() {
	Super::BeginPlay();
	auto controlledTank = GetControlledTank();
	ATank* playerTank = GetPlayerTank();

	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("ATank_AI_Controller not possessing a tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("ATank_AI_Controller Possessing: %s"), *(controlledTank->GetName()));
	}
	if (playerTank == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("ATank_AI_Controller %s has not found FirstPlayerController"), *(controlledTank->GetName()));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("ATank_AI_Controller %s found FirstPlayerController: %s"), *(playerTank->GetName()), *(GetPlayerTank()->GetName()));
	}
}
//
//void ATank_AI_Controller::Tick(float deltaTime) {
//	Super::Tick(deltaTime);
//	AimTowardsEnemy();
//	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
//}
//
ATank* ATank_AI_Controller::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
//
ATank* ATank_AI_Controller::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATank_AI_Controller::Tick(float deltaSeconds) {
	Super::Tick(deltaSeconds);
	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

//
//void ATank_AI_Controller::AimTowardsEnemy() {
//	if (!GetControlledTank()) {
//		return;
//	}
//	FVector HitLocation;
//	if (GetSightRayHitLocation(HitLocation)) {
//		//UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *HitLocation.ToString());
//	}
//}
//
//bool ATank_AI_Controller::GetSightRayHitLocation(FVector& hitLocation) const {
//	int32 viewPortSize_X, viewPortSize_Y;
//	GetWorld()->GetFirstPlayerController()->GetViewportSize(viewPortSize_X, viewPortSize_Y);
//	auto screenLocation = FVector2D(viewPortSize_X* crossHair_Position_X, viewPortSize_Y * crossHair_Position_Y);
//	//UE_LOG(LogTemp, Warning, TEXT("Screen location: %s"), *(screenLocation.ToString()));
//	hitLocation = FVector(1.0f);
//	FVector lookDirection;
//	if (GetLookDirection(screenLocation, lookDirection)) {
//		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *lookDirection.ToString());
//	}
//	return true;
//}
//
//bool  ATank_AI_Controller::GetLookDirection(FVector2D screenLocation, FVector& worldDirection) const {
//	FVector cameraWorldLocation;
//	return (GetWorld()->GetFirstPlayerController()->DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, worldDirection));
//}