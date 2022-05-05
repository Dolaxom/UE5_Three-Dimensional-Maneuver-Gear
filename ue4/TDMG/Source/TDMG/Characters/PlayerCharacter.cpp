#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "TDMG/Actors/Projectiles/TDMGProjectile.h"

APlayerCharacter::APlayerCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = 1;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
}

void APlayerCharacter::MoveForward(float Value)
{
	Super::MoveForward(Value);

	if(!FMath::IsNearlyZero(Value, 1e-6f))
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector ForwardVector = YawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardVector, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	Super::MoveRight(Value);

	if(!FMath::IsNearlyZero(Value, 1e-6f))
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector RightVector = YawRotator.RotateVector(FVector::RightVector);
		AddMovementInput(RightVector, Value);
	}
}

void APlayerCharacter::Turn(float Value)
{
	Super::Turn(Value);

	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	Super::LookUp(Value);
	
	AddControllerPitchInput(Value);
}

void APlayerCharacter::ProcessHit(const FHitResult& HitResult, const FVector& Direction)
{
	FVector ShotStart = HitResult.TraceStart;
	FVector ShotEnd = HitResult.ImpactPoint;
	float ShotDistance = (ShotStart - ShotEnd).Size();
	
	UE_LOG(LogTemp, Warning, TEXT("ABOBA!!!"));
	GetCharacterMovement()->AddImpulse(this->GetActorForwardVector() * 1000, true);
}

void APlayerCharacter::StartFire()
{
	Super::StartFire();

	const FRotator SpawnRot = GetActorRotation();
	const FVector SpawnLocOne = GetActorLocation() + SpawnRot.RotateVector(FiringOffsetOne);
	const FVector SpawnLocTwo = GetActorLocation() + SpawnRot.RotateVector(FiringOffsetTwo);

	ATDMGProjectile* ProjectileFirst = GetWorld()->SpawnActor<ATDMGProjectile>(ProjectileClass, SpawnLocOne, SpawnRot);
	ATDMGProjectile* ProjectileSecond = GetWorld()->SpawnActor<ATDMGProjectile>(ProjectileClass, SpawnLocTwo, SpawnRot);
	
	if(!IsValid(ProjectileFirst) || !IsValid(ProjectileSecond))
	{
		return;
	}

	ProjectileFirst->OnProjectileHitEvent.AddDynamic(this, &APlayerCharacter::ProcessHit);
	ProjectileSecond->OnProjectileHitEvent.AddDynamic(this, &APlayerCharacter::ProcessHit);
}

void APlayerCharacter::StopFire()
{
	Super::StopFire();
}






