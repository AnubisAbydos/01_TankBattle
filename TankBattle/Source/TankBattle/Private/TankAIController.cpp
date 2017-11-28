// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Can't find Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found Player: %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetPlayerTank())
	{
		// TODO Move towards player

		// Aim towards PLayer
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire If Ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{ 
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}


