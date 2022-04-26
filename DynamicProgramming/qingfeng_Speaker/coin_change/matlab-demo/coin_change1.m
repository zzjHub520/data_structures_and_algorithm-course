function f=coin_change1(coins, S)
    FF = +inf*ones(1, S+2);
    
    FF(S+2)=0;
    for x=1:S
        tmp = x - coins;
        tmp(tmp<0) = S+1;
        tmp(tmp==0) = S+2;
        tmp1=FF(tmp);
        FF(x)=min(tmp1)+1;
    end
    if FF(S)<+inf
        f=FF(S);
    else
        f=-1;
    end
end