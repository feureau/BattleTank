// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiming_ActorComponent.h"

// Sets default values for this component's properties
UTankAiming_ActorComponent::UTankAiming_ActorComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAiming_ActorComponent::AimAt(FVector worldSpaceAimTargetLocation, float launchspeed) {
	if (barrel == nullptr) {
		return;
	}
	FVector outLaunchVelocity;
	FVector barrelLocation = barrel->GetSocketLocation(FName("Projectile Launch Socket"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVelocity, barrelLocation, worldSpaceAimTargetLocation, launchspeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bHaveAimSolution) {
		auto aimDirection = outLaunchVelocity.GetSafeNormal();
		FString currentTankName = GetOwner()->GetName();
		float time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("Aim solution found. Time: %s"), *(FString::SanitizeFloat(time)));
		UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s from: %s. Firing at %s"), *currentTankName, *worldSpaceAimTargetLocation.ToString(), *barrelLocation.ToString(), *aimDirection.ToString());
		MoveBarrelTowards(aimDirection);
	} else {
		float time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("No aim solution found. Time: %s"), *(FString::SanitizeFloat(time)));
	}
}

void UTankAiming_ActorComponent::SetBarrelReference(UTankBarrel_StaticMeshComponent* barrelToSet) {
	barrel = barrelToSet;
}

// Called when the game starts
void UTankAiming_ActorComponent::BeginPlay() {
	Super::BeginPlay();

	// ...
}

// Called every frame
void UTankAiming_ActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAiming_ActorComponent::MoveBarrelTowards(FVector aimDirection) {
	auto barrelRotator = barrel->GetForwardVector().Rotation();
	auto aimAsRotator = aimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *aimAsRotator.ToString());
	barrel->Elevate(deltaRotator.Pitch);
}