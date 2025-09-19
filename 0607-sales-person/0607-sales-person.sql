SELECT name
FROM SalesPerson
WHERE name NOT IN (
    SELECT t1.name
    FROM SalesPerson AS t1 JOIN Orders USING(sales_id) JOIN Company USING(com_id)
    WHERE Company.name = "RED"
)
#GROUP BY project_id
#ORDER BY score DESC