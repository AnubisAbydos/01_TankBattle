// Copyright Silent Neon (Lex Hall)

#include "TankBattle.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO Check Radius

		// Aim towards PLayer
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire If Ready
		ControlledTank->Fire();
	}
}


