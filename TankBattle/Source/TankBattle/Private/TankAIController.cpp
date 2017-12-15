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
	auto ControlledTankAimComp = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(PlayerTank && ControlledTankAimComp)) { return; }

	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO Check Radius

	// Aim towards PLayer
	ControlledTankAimComp->AimAt(PlayerTank->GetActorLocation());

	// Fire If Ready
	ControlledTankAimComp->Fire();

}


