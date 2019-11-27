// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"
#include "TankPlayerController.h"

ATankAIController::ATankAIController()
{
	//Super::Super();
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = nullptr;
	Tank = GetControlledTank();
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller BeginPlay with controlled tank %s"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller BeginPlay with No Tank controlled"));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller BeginPlay found player tank %s"), *PlayerTank->GetName());
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller BeginPlay found No player tank"));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>( PlayerPawn );

}