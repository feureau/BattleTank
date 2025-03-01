// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel_StaticMeshComponent.h"

void ATank::AimAt(FVector targetLocation) {
	tankAimingComponent->AimAt(targetLocation, launchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel_StaticMeshComponent* barrelToSet) {
	tankAimingComponent->SetBarrelReference(barrelToSet);
}

// Sets default values
ATank::ATank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// No need to protect points as added at construction
	tankAimingComponent = CreateDefaultSubobject<UTankAiming_ActorComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ATank::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}