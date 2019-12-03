// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max counterclock wise rotation speed, +1 is max clockwise rotation speed
	void Rotate(float RelativeSpeed);

protected:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 25.f;

};
