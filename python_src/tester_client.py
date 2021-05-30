import grpc

import file_pb2
import file_pb2_grpc

PORT = 'localhost:50051'
TIMEOUT_SECONDS = 3


def sum(stub, a, b):
  request = file_pb2.InputData(a=a, b=b)
  response = stub.Sum(request, TIMEOUT_SECONDS)
  return response.res

# way 1
def main():
  channel = grpc.insecure_channel(PORT)
  stub = file_pb2_grpc.SummatorStub(channel)

  # some sample data for testing
  print('Running sample data...')
  x, y = 6, 4
  result = sum(stub, x, y)
  print(result) # prints 10

# way 2
def run():
  with grpc.insecure_channel('localhost:50051') as channel:
    stub = file_pb2_grpc.SummatorStub(channel)
    request = file_pb2.InputData(a=2, b=3)
    response = stub.Sum(request, TIMEOUT_SECONDS)
    print(response.res) # prints 5

if __name__ == '__main__':
  main()
  run()