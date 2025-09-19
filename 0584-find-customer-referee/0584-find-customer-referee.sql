SELECT name
FROM Customer AS t1
WHERE referee_id IS NULL OR t1.referee_id != 2