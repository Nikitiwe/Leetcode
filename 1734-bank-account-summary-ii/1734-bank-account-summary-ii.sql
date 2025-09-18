SELECT name,
       SUM(amount) AS balance
FROM Users
     INNER JOIN Transactions USING(account)
GROUP BY name
HAVING balance > 10000