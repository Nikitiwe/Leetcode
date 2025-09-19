SELECT actor_id,
        director_id
FROM ActorDirector AS t1
GROUP BY 1, 2
HAVING COUNT(*) >= 3