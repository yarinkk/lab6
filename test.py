import subprocess
import sys
import unittest

TEST_CASES = [
    (
        """1
Ivan
60
5
170
""",
        """Ivan 60 5 170 100 Excellent
"""
    ),
    (
        """1
Oleg
30
20
150
""",
        """Oleg 30 20 150 0 Bad
"""
    ),
]

class ProgramOutputTests(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.program_path = sys.argv[1]

    def run_program(self, input_data):
        result = subprocess.run(
            [self.program_path],
            input=input_data,
            text=True,
            capture_output=True
        )
        return result.stdout

    def test_all(self):
        for inp, out in TEST_CASES:
            self.assertEqual(self.run_program(inp), out)

if __name__ == "__main__":
    unittest.main()