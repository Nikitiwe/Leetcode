SELECT user_id, COUNT(*) AS followers_count
FROM Followers AS t1
GROUP BY user_id
ORDER BY user_id ASC