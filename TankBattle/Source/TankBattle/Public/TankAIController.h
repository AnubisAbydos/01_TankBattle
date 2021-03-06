// Copyright Silent Neon (Lex Hall)

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 10000;
};
