# Simple script to run all problem tests
# Save as runall.ps1 in PROBLEM SET 1 directory

Write-Host "=== PROBLEM 1 ===" -ForegroundColor Green
Push-Location "Problem 1"
Write-Host "Testing with Parallelogram.txt:" -ForegroundColor Yellow
.\polygon_test.exe Parallelogram.txt
Write-Host "`nTesting with Data.txt:" -ForegroundColor Yellow
.\polygon_test.exe Data.txt
Pop-Location

Write-Host "`n=== PROBLEM 2 ===" -ForegroundColor Green
Push-Location "Problem 2"
.\polynomial_test.exe
Pop-Location

Write-Host "`n=== PROBLEM 3 ===" -ForegroundColor Green
Push-Location "Problem 3"
.\combination_test.exe
Pop-Location

Write-Host "`n=== PROBLEM 4 ===" -ForegroundColor Green
Push-Location "Problem 4"
.\bernstein_test.exe
Pop-Location

Write-Host "`nAll tests completed!" -ForegroundColor Cyan
