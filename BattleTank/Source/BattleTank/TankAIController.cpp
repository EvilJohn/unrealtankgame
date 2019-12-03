// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"

ATankAIController::ATankAIController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		
		// TODO Move toward player

		// Aim Toward Player
		AITank->AimAt(PlayerTank->GetActorLocation());
		
		// Fire if ready
		AITank->Fire();
	}
}
