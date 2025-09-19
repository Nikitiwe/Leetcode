SELECT p1.category AS category1, p2.category AS category2,
       COUNT(DISTINCT CASE WHEN t1.user_id = t2.user_id THEN t1.user_id END) AS customer_count
FROM ProductPurchases AS t1 JOIN ProductInfo AS p1 ON t1.product_id = p1.product_id CROSS JOIN ProductPurchases AS t2 JOIN ProductInfo AS p2 ON t2.product_id = p2.product_id
WHERE p1.category < p2.category
GROUP BY 1, 2
HAVING customer_count >= 3
ORDER BY customer_count DESC, category1 ASC, category2 ASC