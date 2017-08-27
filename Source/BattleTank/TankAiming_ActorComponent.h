// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankBarrel_StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "TankAiming_ActorComponent.generated.h"
// Forward Declaration.
class UTankBarrel_StaticMeshComponent;

// Hold barrel's properties and elevate method.
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAiming_ActorComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAiming_ActorComponent();
	void AimAt(FVector worldSpaceAimTargetLocation, float launchspeed);
	void SetBarrelReference(UTankBarrel_StaticMeshComponent* barrelToSet);
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void MoveBarrelTowards(FVector aimDirection);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UTankBarrel_StaticMeshComponent* barrel = nullptr;
};
