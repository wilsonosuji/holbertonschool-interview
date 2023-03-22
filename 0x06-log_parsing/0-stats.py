#!/usr/bin/python3
""" reads stdin line by line and computes metrics """

if __name__ == '__main__':

    import sys
    import collections

    cont = 0
    size = 0
    status = {'200': 0, '301': 0, '400': 0, '401': 0,
              '403': 0, '404': 0, '405': 0, '500': 0}

    try:
        for line in sys.stdin:
            cont += 1
            fs = line.split()

            try:
                size += int(fs[-1])

                for keys in status.keys():
                    if keys == fs[-2]:
                        status[keys] += 1
            except:
                pass

            if cont == 10:
                print('File size: {}'.format(size))
                od = collections.OrderedDict(sorted(status.items()))
                for keys, values in od.items():
                    if values != 0:
                        print('{}: {}'.format(keys, values))
                cont = 0

    except KeyboardInterrupt:
        print('File size: {}'.format(size))
        od = collections.OrderedDict(sorted(status.items()))
        for keys, values in od.items():
            if values != 0:
                print('{}: {}'.format(keys, values))
        raise

    print('File size: {}'.format(size))
    od = collections.OrderedDict(sorted(status.items()))
    for keys, values in od.items():
        if values != 0:
                print('{}: {}'.format(keys, values))
