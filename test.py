print('****************************************')
print('欢迎光临小象奶茶馆！\n小象奶茶馆售卖宇宙无敌奶茶!\n奶茶虽好，可不要贪杯哦！\n每次限尝鲜一种口味：\n1. 原味冰奶茶 3元 \n2. 香蕉冰奶茶 5元 \n3. 草莓冰奶茶 5元  \n4. 蒟蒻冰奶茶 7元  \n5. 珍珠冰奶茶 7元 ')
print('****************************************')

milktea_num=4
milktea_quantity=2
if_vip='y'
if milktea_num==1:
    milktea_price=3
    total= milktea_price*milktea_quantity
    print('您购买的是{}号奶茶，共购买{}杯，总计{}元'.format(milktea_num,milktea_quantity,tatal))
    if if_vip=='y':
        total*=0.9
        print('您可以享受会员价，折后总价：{}元'.format(total))
    else:
        print('不好意思哦，您目前还不是我们的会员，\n本次无法享受会员价喽，永远爱你么么哒')
elif milktea_num==2 or milktea_num==3:
    milktea_price=5
    total= milktea_price*milktea_quantity
    print('您购买的是{}号奶茶，共购买{}杯，总计{}元'.format(milktea_num,milktea_quantity,tatal))
    if if_vip=='y':
        total*=0.9
        print('您可以享受会员价，折后总价：{}元'.format(total))
    else:
        print('不好意思哦，您目前还不是我们的会员，\n本次无法享受会员价喽，永远爱你么么哒')
elif milktea_num==4 or milktea_num==5:
    milktea_price=7
    total= milktea_price*milktea_quantity
    print('您购买的是{}号奶茶，共购买{}杯，总计{}元'.format(milktea_num,milktea_quantity,tatal))
    if if_vip=='y':
        total*=0.9
        print('您可以享受会员价，折后总价：{}元'.format(total))
    else:
        print('不好意思哦，您目前还不是我们的会员，\n本次无法享受会员价喽，永远爱你么么哒')
else:
    print('我还是个小宝宝，您的输入我看不懂，您拿着小票问问小象君吧')
print('****************************************')
print('****************************************')
print('做一枚有态度、有思想的奶茶馆（傲娇脸）！\n\t祝您今日购物愉快！\n\t\t诚挚欢迎您再次光临！')
print('****************************************')