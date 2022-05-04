#include "TDMGProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

ATDMGProjectile::ATDMGProjectile()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Block);
	SetRootComponent(MeshComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement Component"));
	ProjectileMovementComponent->InitialSpeed = 1500.f;
}

void ATDMGProjectile::LaunchProjectile(FVector Direction)
{
	FVector Velocity = ProjectileMovementComponent->Velocity;
	float Speed = ProjectileMovementComponent->InitialSpeed;
	Velocity = Direction * Speed;
	MeshComponent->IgnoreActorWhenMoving(GetOwner(), true);
	OnProjectileLaunched();
}

void ATDMGProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComponent->OnComponentHit.AddDynamic(this, &ATDMGProjectile::OnCollisionHit);
}

void ATDMGProjectile::OnProjectileLaunched()
{
	
}

void ATDMGProjectile::OnCollisionHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(OnProjectileHitEvent.IsBound())
	{
		OnProjectileHitEvent.Broadcast(Hit, ProjectileMovementComponent->Velocity.GetSafeNormal());
	}
}


