# 프로젝트 문제 1번

# 입력
print("입력")
input = [10, 40, 30, 60, 30]
print(input)

def problem1(input):
    # 평균은 전체 합을 요소 개수로 나눈 값
    mean = sum(input) // len(input)

    # 중앙값을 구하기 위해 리스트를 정렬
    sorted_input = sorted(input)
    # 다섯 개의 수가 주어지므로 중앙값은 정렬된 리스트의 가운데 값 (인덱스 2)
    median = sorted_input[2]

    # 결과 리스트에 평균과 중앙값 저장
    result = [mean, median]
    return result

# 함수 호출 및 결과 저장
result = problem1(input)

# 출력
print("출력")
print(result[0])
print(result[1])

# 결과가 정답과 일치하는지 검증
assert result == [34, 30]
print("정답입니다.")
