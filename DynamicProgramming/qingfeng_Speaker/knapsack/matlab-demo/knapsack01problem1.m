function f=knapsack01problem1(p,w,W)

m=length(p);
FF=zeros(m,W);

if w(1)<=W
    FF(1,w(1):end)=p(1);
end

for i=2:m
    FF(i,1)=max([p(w(1:i)==1),0]);
end

for i=2:m
    for j=2:W
        if w(i)>j
            FF(i,j)=FF(i-1,j);
        elseif w(i)==j
            FF(i,j)=max(FF(i-1,j),p(i));
        else
            FF(i,j)=max(FF(i-1,j),p(i)+FF(i-1,j-w(i)));
        end
    end
end
f=FF(m,W);
end