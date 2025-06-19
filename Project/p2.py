# 프로젝트 문제 2번
input = ")))()"

def problem2(input):
    # 올바른 괄호열로 만들기 위해 앞/뒤에 추가해야 하는 괄호 수를 계산
    open_needed = 0   # 앞에 붙여야 할 '(' 개수
    close_needed = 0  # 닫히지 않은 '(' 개수

    for char in input:
        if char == '(':
            # 여는 괄호는 닫히길 기다리므로 close_needed 증가
            close_needed += 1
        elif char == ')':
            if close_needed > 0:
                # 닫을 수 있는 여는 괄호가 있으면 닫기
                close_needed -= 1
            else:
                # 닫을 여는 괄호가 없으면 앞에 여는 괄호가 필요
                open_needed += 1

    # 전체 추가해야 할 괄호 수는
    # 앞에 붙일 '(' 수 (open_needed) + 뒤에 붙일 ')' 수 (close_needed)
    result = open_needed + close_needed
    return result

result = problem2(input)

print(result)

assert result == 3
print("정답입니다.")
