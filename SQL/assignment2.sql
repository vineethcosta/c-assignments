/*create table dept(
  deptno int,
  dname  varchar(20),
  loc    varchar(20)
  constraint pk_dept primary key (deptno)
);

create table emp(
  empno    int,
  ename    varchar(20),
  job      varchar(20),
  mgr      int,
  hiredate date,
  sal      int,
  comm     int,
  deptno   int,
  constraint pk_emp primary key (empno),
  constraint fk_deptno foreign key (deptno) references dept (deptno)
);
insert into dept
values(10, 'ACCOUNTING', 'NEW YORK');
insert into dept
values(20, 'RESEARCH', 'DALLAS');
insert into dept
values(30, 'SALES', 'CHICAGO');
insert into dept
values(40, 'OPERATIONS', 'BOSTON');
/*inserting values into emp table*/
 insert into emp
values(
 7839, 'KING', 'PRESIDENT', null,
 datefromparts(1981,11,17),
 5000, null, 10
);
insert into emp
values(
 7698, 'BLAKE', 'MANAGER', 7839,
 datefromparts(1981,5,1),
 2850, null, 30
);
insert into emp
values(
 7782, 'CLARK', 'MANAGER', 7839,
 datefromparts(1981,6,9),
 2450, null, 10
);
insert into emp
values(
 7566, 'JONES', 'MANAGER', 7839,
 datefromparts(1981,4,2),
 2975, null, 20
);
insert into emp
values(
 7788, 'SCOTT', 'ANALYST', 7566,
 datefromparts(1987,7,13),
 3000, null, 20
);
insert into emp
values(
 7902, 'FORD', 'ANALYST', 7566,
 datefromparts(1981,12,3),
 3000, null, 20
);
insert into emp
values(
 7369, 'SMITH', 'CLERK', 7902,
 datefromparts(1980,12,17),
 800, null, 20
);
insert into emp
values(
 7499, 'ALLEN', 'SALESMAN', 7698,
 datefromparts(1981,2,20),
 1600, 300, 30
);
insert into emp
values(
 7521, 'WARD', 'SALESMAN', 7698,
 datefromparts(1981,2,22),
 1250, 500, 30
);
insert into emp
values(
 7654, 'MARTIN', 'SALESMAN', 7698,
 datefromparts(1981,9,28),
 1250, 1400, 30
);
insert into emp
values(
 7844, 'TURNER', 'SALESMAN', 7698,
 datefromparts(1981,9,8),
 1500, 0, 30
);
insert into emp
values(
 7876, 'ADAMS', 'CLERK', 7788,
 datefromparts(1987,7,13),
 1100, null, 20
);
insert into emp
values(
 7900, 'JAMES', 'CLERK', 7698,
 datefromparts(1981,12,3),
 950, null, 30
);
insert into emp
values(
 7934, 'MILLER', 'CLERK', 7782,
 datefromparts(1982,1,23),
 1300, null, 10
);*/

--Q3
select job from emp
group by job;

--Q4
select * from emp
where deptno=10 OR deptno=20
order by ename;

--Q5
select ename , job from emp
where job='clerk' AND deptno=20;
--Q12

select min(sal) "minimum salary",max(sal)"maximum salary" ,job from emp group by job;

--Q13
select  count(mgr) from emp;

--Q14
select avg(sal) "average salary",sum(sal)+sum(isnull(comm,0)) "total renumeration",job "job name" from emp group by job;

--Q15
select max(sal)-min(sal) "difference" from emp;

--Q16
select * from dept x where deptno in (select deptno from emp where count(deptno)>3)


--Q18
select min(sal) as x from emp 
where mgr in(select mgr from emp where sal=x)

--Q19
select e.ename , d.dname from emp e, dept d where d.deptno=e.deptno order by d.dname;




--Q20
select e.ename , e.deptno , d.dname from emp e, dept d where d.deptno=e.deptno;

--Q21
select sal/12 "per month salary" from emp where sal/12 >150
order by sal;






--Q24
select * from emp where job !='clerk' order by sal desc;

--Q25
select * from emp where sal>1000 AND job='CLERK';

--Q26
select d.deptno d.dname from dept d where d.deptno NOT IN(select e.deptno from emp e); 











--Q27
select ename,sal,job from emp where sal IN (select max(sal) as msal from emp 
group by job )
order by sal desc;

--Q28
select eno,job from emp
group by job
order by hiredate desc;

select deptno "deptno",max(hiredate) "recent hired" from emp
group by deptno;

--Q29
select count(*) "count of emp",sum(sal) "total salary", avg(sal) "average salary"
from emp
group by deptno;


