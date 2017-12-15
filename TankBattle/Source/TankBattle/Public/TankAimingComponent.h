// Copyright Silent Neon (Lex Hall)

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for Aiming State
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};


// Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Aiming;

public:	
	void AimAt(FVector HitLocation);

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurretTowards(FVector AimDirection);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 8000;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile>ProjectileBlueprint;
	
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	float ReloadTimeSecs = 3;

	double LastFireTime = 0;
};
