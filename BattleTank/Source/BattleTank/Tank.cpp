// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "Engine/StaticMeshSocket.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"
#include "TankProjectileMovementComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
	//Super::Super();
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
		
}
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelReference)
{
	TankAimingComponent->SetBarrelReference(BarrelReference);
	Barrel = BarrelReference;
}
            
void ATank::SetTurretReference(UTankTurret* TurretReference)
{
	TankAimingComponent->SetTurretReference(TurretReference);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && isReloaded)
	{
		// Spawn a projectile at the socket location of the barrel
		auto Location = Barrel->GetSocketLocation(FName("Projectile"));
		auto Rotation = Barrel->GetSocketRotation(FName("Projectile"));

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}
