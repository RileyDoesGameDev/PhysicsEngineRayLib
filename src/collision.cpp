#include "collision.h"
#include "raymath.h"
#include "mathUtils.h"
bool Intersects(Body* bodyA, Body* bodyB)
{
	float distance = Vector2Distance(bodyA->position, bodyB->position);
	float radius = bodyA->size + bodyB->size;

	return (distance <= radius);
}



void CreateContacts(const bodies_t& bodies, contacts_t& contacts)
{
	for (int i = 0; i < bodies.size(); i++)
	{
		Body* bodyA = bodies[i];
		for (int j = i + 1; j < bodies.size(); j++)
		{
			Body* bodyB = bodies[j];
			if (bodyA->type != Body::Type::Dynamic && bodyB->type != Body::Type::Dynamic) continue;//<both bodies are not dynamic) continue;

			if (Intersects(bodyA, bodyB))
			{
				Contact contact;
				contact.bodyA = bodyA;
				contact.bodyB = bodyB;

				Vector2 direction = bodyA->position - bodyB->position;//<direction vector from bodyB to bodyA>;
				float distanceSqr = Vector2LengthSqr(direction);//<get Vector2 Length Squared of direction>;
				if (distanceSqr <= EPSILON)
				{
					direction = Vector2{ randomf(-0.05f, 0.05f), randomf(-0.05f, 0.05f) };
					distanceSqr = Vector2LengthSqr(direction);
				}

				float distance = sqrtf(distanceSqr); //<get distance from squared distance>;
				float radius = bodyA->size + bodyB->size;// <add size of bodyA and bodyB>;
				contact.depth = radius - distance;//<calculate penetration depth, see note above>;
				contact.normal = Vector2Normalize(direction);//<normalize direction, can use normalize function or direction / distance>;
				contact.restitution =  bodyA->restitution - bodyB->restitution;//<get average restitution of both bodies>;

				contacts.push_back(contact);
			}
		}
	}
}

void SeparateContacts(contacts_t& contacts)
{
	for (auto contact : contacts)
	{
		float totalInverseMass = contact.bodyB->invMass + contact.bodyA->invMass ;//<add inverse mass of both contact bodies>;
		Vector2 separation = contact.normal * (contact.depth / totalInverseMass);
		contact.bodyA->position = contact.bodyA->position + (separation * contact.bodyA->invMass);
		contact.bodyB->position = contact.bodyB->position - (separation * contact.bodyB->invMass);
	}
}

void ResolveContacts(contacts_t& contacts)
{
	for (auto& contact : contacts)
	{
		// compute relative velocity
		Vector2 rv = contact.bodyA->velocity - contact.bodyB->velocity;
			// project relative velocity onto the contact normal
		float nv = Vector2DotProduct(rv,contact.normal);   //<dot product of rv and contact normal, use Vector2DotProduct>

			// skip if bodies are separating
			if (nv > 0) continue;

		// compute impulse magnitude
			float totalInverseMass = contact.bodyA->invMass + contact.bodyB->invMass;
			float impulseMagnitude = -(1 + contact.restitution) * nv / totalInverseMass;

		// compute impulse vector
			Vector2 impulse = contact.normal * impulseMagnitude; //<scale(multiply) contact normal with impulse magnitude>

			// apply impulses to both bodies
			contact.bodyA->ApplyForce(impulse, Body::ForceMode::Impulse);
		contact.bodyB->ApplyForce(Vector2Negate(impulse), Body::ForceMode::Impulse);
	}
}