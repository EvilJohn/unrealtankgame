// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
// Movable Tank Barrel
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward movement, +1 is max upward movement
	void Elevate(float RelativeSpeed);

protected:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 70.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0.f;

};
