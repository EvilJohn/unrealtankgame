// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATankPlayerController::ATankPlayerController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* Tank = nullptr;
	Tank = GetControlledTank();
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play with controlled tank %s"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play with No Tank controlled"));
	}

}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look direction %s"), *HitLocation.ToString()); 
		// TODO tell the controlled tank to aim to this point
	}
}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Ray Cast through the cross hair
	// if hits terrain 
	//   return true, and set World hit location in OutHitLocation
	// else
	//   return false

	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	this->GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// "De-project te screen position of the crosshair to a world direction
	FVector LookDirection;
	if ( GetLookDirection(ScreenLocation, LookDirection) )
	{
		UE_LOG(LogTemp, Warning, TEXT("LookDirection %s"), *LookDirection.ToString())
	}
	// Line-trace along the LookDirection and see what's hit (up to max ranage)

	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const
{
	FVector CameraWorldLocation; // Discard these values
	return this->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, OutLookDirection);
}
