// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	auto Time = GetWorld()->GetTimeSeconds();

	//UE_LOG(LogTemp, Warning, TEXT("%f: Turret->Rotate(%f) from RelativeSpeed of %f "), Time, Rotation, RelativeSpeed);

	SetRelativeRotation(FRotator(0, Rotation, 0));

}