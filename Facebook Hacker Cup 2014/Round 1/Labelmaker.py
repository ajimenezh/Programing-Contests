import math;

input = open('input.txt', 'r');
output = open('output.txt', 'w');

t = int(input.readline());

for i in range(t):

    s = input.readline();

    vs = s.split(' ');

    s = vs[0];

    m = int(vs[1]);
    print(m)
    n = len(s);

    if (n==1):
        output.write("Case #" + str(i+1) + ": ");
        for j in range(m):
            output.write(s);
        output.write("\n");
    else:
        tmp = n;
        while (m>0):
            if (m<=tmp):
                break;
            m = m - tmp;
            tmp = tmp*n;

        ans = "";

        tmp = tmp//n;
        while (tmp>0):
            if (tmp!=1):
                ans = ans + s[(m-1)//tmp];
            else:
                ans = ans + s[m-1];
            if (m%tmp!=0):
                m = m%tmp;
            else:
                m = tmp;
            tmp = tmp//n;
        output.write("Case #" + str(i+1) + ": ");
        output.write(ans);
        output.write("\n");
        print(ans);

output.close();
