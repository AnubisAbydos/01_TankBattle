// Copyright Silent Neon (Lex Hall)

#include "TankBattle.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	// move Turret right amount this frame given max speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}

