// Copyright Silent Neon (Lex Hall)

#include "TankBattle.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(PlayerTank && AimingComponent)) { return; }

	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO Check Radius

	// Aim towards PLayer
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire If Ready
	if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
	{
		AimingComponent->Fire();
	}

}


