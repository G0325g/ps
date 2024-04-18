-- 코드를 작성해주세요
SELECT YEAR(a.DIFFERENTIATION_DATE) as YEAR, 
       b.size - a.SIZE_OF_COLONY as YEAR_DEV,
       a.ID
from ECOLI_DATA a 
JOIN
(
    SELECT YEAR(DIFFERENTIATION_DATE) YEAR, 
           MAX(SIZE_OF_COLONY) size
    from ECOLI_DATA
    GROUP BY YEAR(DIFFERENTIATION_DATE)
) b
ON YEAR(a.DIFFERENTIATION_DATE) = b.YEAR
ORDER BY YEAR asc, YEAR_DEV asc;