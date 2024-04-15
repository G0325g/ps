-- 코드를 입력하세요
SELECT f.FLAVOR 
from FIRST_HALF as f JOIN JULY as j
ON f.FLAVOR = j.FLAVOR
group by f.FLAVOR
order by (sum(j.TOTAL_ORDER) + sum(f.TOTAL_ORDER)) DESC
LIMIT 3;