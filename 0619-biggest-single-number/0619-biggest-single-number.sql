SELECT 
  CASE 
    WHEN (SELECT num
          FROM MyNumbers AS t1
          GROUP BY num
          HAVING COUNT(*) = 1
          ORDER BY num DESC
          LIMIT 1) IS NOT NULL 
    THEN (SELECT num
          FROM MyNumbers AS t1
          GROUP BY num
          HAVING COUNT(*) = 1
          ORDER BY num DESC
          LIMIT 1)
    ELSE NULL
  END AS num;