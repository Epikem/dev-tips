
        # 의사 코드를 써보자. 먼저 현재 인덱스가 k라고 하고,
        # k번째 날에 만료되는 상담이 있는지 확인한다. 
        if(nn+t-1>n):
            it(nn,t,n,nn+t-1,n)
            p = -9999999
        if(nn in limits.keys()):
            # 있다면, 그 키쌍의 값들을 꺼내고 키쌍은 제거한다.
            values = limits.pop(nn)
            maxp = 0
            maxd = 0
            for d in values:
                # 여기에 있는 각 날짜 d들을 순회하면서, 가장 높은 profits[d]를 찾는다.
                # 그 날짜 d를 외워둔다.
                if(profits[d] > maxp):
                    maxp=profits[d]
                    maxd = d
            # 오늘 날짜의 최고 값은 k_p + profits[d_max]가 된다.
            profits[nn] = p + profits[maxd] if p + profits[maxd]>profits[nn-1]+p else profits[nn-1]+p
            # 오늘의 상담이 끝나는 그 다음날에 오늘을 등록한다.
            if(nn+t in limits.keys()):
                limits[nn+t].append(nn)
            else:
                limits[nn+t]=[nn]
        else:
            # 오늘 날짜의 최고 값은 k_p가 된다.
            profits[nn] = p if p>profits[nn-1] else profits[nn-1]
            # 오늘의 상담이 끝나는 그 다음날에 오늘을 등록한다.
            if(nn+t in limits.keys()):
                limits[nn+t].append(nn)
            else:
                limits[nn+t]=[nn]

            pass
