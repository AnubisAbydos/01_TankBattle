// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "TankPlayerController.h"

	

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Not Possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Possesing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())	{ return; }

	FVector HitLocation; // OUT parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim here
	}
}

// Get world location of line trace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{				
	OutHitLocation = FVector(1.0);
	return true;
}