select newuid, t3.month, t4.company_name,
sum("账单收入") as "账单收入" , sum("牛币") as "牛币" , sum("订单收入")  as "订单收入" ,sum("账单收入"+"牛币"+"订单收入") as "总收入"from
(select t1.uid as newuid,t1.month,(0-t1.after_tax_moneyX-t1.after_tax_moneyY) as "账单收入",t1.after_tax_moneyY as "牛币",0 as "订单收入"
from ads_fnc.ads_fnc_v2_income_product_mf t1
where t1.dt in('2022-04-01')
and t1.month in ('2022-04-01')
and t1.product='机器托管'
and t1.is_internal=false
union all
select t2.uid,t2.month,0,0,t2.income/1.06/10000 from ads_fnc.ads_fnc_income_order_mf t2
where t2.dt in ('2022-04-01')
and t2.month in ('2022-04-01')
and t2.seller_id=54) t3

left join dwd.dwd_usr_user360_baseinfo_df t4 on t3.newuid=t4.uid
where t4.dt='2022-05-08'
and t4.is_internal=false
group by newuid,t3.month,t4.company_name