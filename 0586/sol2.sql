-- Follow up: What if more than one customer has the largest number of orders, 
-- can you find all the customer_number in this case?

SELECT 
    customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(order_number) = (
    SELECT 
    COUNT(order_number) as count_orders
    FROM Orders
    GROUP BY customer_number
    ORDER BY count_orders DESC
    LIMIT 1
    )