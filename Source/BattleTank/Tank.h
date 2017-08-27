// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAiming_ActorComponent.h"
#include "Tank.generated.h"
class UTankBarrel_StaticMeshComponent;
UCLASS()
class BATTLETANK_API ATank : public APawn {
	GENERATED_BODY()

public:
	void AimAt(FVector targetLocation);
	UFUNCTION(BlueprintCallable, Category = Setup) void SetBarrelReference(UTankBarrel_StaticMeshComponent* barrelToSet);
protected:
	UTankAiming_ActorComponent* tankAimingComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	ATank();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = Firing) float launchSpeed = 100000; // sensible starting value of 1000m/s
};
