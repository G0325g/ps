-- 코드를 입력하세요
SELECT DISTINCT USER_ID, PRODUCT_ID
    FROM ONLINE_SALE
    GROUP BY USER_ID,PRODUCT_ID
    HAVING count(PRODUCT_ID)>1
    ORDER BY USER_ID ASC, PRODUCT_ID DESC;