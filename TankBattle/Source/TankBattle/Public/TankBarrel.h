// Copyright Silent Neon (Lex Hall)

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max down movement and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 10;

	UPROPERTY(EditAnywhere)
	float MaxElevationDegrees = 35;

	UPROPERTY(EditAnywhere)
	float MinElevationDegrees = 0;


	
};
