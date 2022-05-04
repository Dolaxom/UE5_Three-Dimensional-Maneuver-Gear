#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

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

void APlayerCharacter::StartFire()
{
	Super::StartFire();
	
	if(!IsValid(ProjectileType))
	{
		return;
	}

	FRotator SpawnRot = GetActorRotation();
	FVector SpawnLocOne = GetActorLocation() + SpawnRot.RotateVector(FiringOffsetOne);
	FVector SpawnLocTwo = GetActorLocation() + SpawnRot.RotateVector(FiringOffsetTwo);
	AActor* SpawnedActorOne = GetWorld()->SpawnActor(ProjectileType, &SpawnLocOne, &SpawnRot);
	AActor* SpawnedActorTwo = GetWorld()->SpawnActor(ProjectileType, &SpawnLocTwo, &SpawnRot);
}

void APlayerCharacter::StopFire()
{
	Super::StopFire();
}




